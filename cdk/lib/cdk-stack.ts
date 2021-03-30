import * as cdk from '@aws-cdk/core';
import * as cognito from '@aws-cdk/aws-cognito'
import * as iam from '@aws-cdk/aws-iam'

export class CdkStack extends cdk.Stack {
  constructor(scope: cdk.Construct, id: string, props?: cdk.StackProps) {
    super(scope, id, props);

    let userpool = new cognito.UserPool(this, 'freertosiosapp', {
      autoVerify: {
        email: true
      }
    })

    let appClient = new cognito.UserPoolClient(this, 'appclient', {
      userPool: userpool,
      generateSecret: true,
    })

    let cognitoClient = new cognito.UserPoolClient(this, 'cognitoclient', {
      userPoolClientName: 'cognitoIdentity',
      userPool: userpool,
    })

    let identitypool = new cognito.CfnIdentityPool(this, 'freertosAppIdentityPool', {
      allowUnauthenticatedIdentities: false,
      
      cognitoIdentityProviders: [
        {
          clientId: cognitoClient.userPoolClientId,
          providerName: userpool.userPoolProviderName,
        }
      ]
    })

    let auth_role = new iam.Role(this, 'freertosAuthRole', {
      assumedBy: new iam.FederatedPrincipal('cognito-identity.amazonaws.com', {
        'ForAnyValue:StringLike': {
          "cognito-identity.amazonaws.com:amr": "authenticated"
        }
      }),
      inlinePolicies: {
        'iotPolicy': new iam.PolicyDocument({
          statements: [
            new iam.PolicyStatement({
              actions: ["iot:AttachPolicy",
                "iot:AttachPrincipalPolicy",
                "iot:Connect",
                "iot:Publish",
                "iot:Subscribe",
                "iot:Receive",
                "iot:GetThingShadow",
                "iot:UpdateThingShadow",
                "iot:DeleteThingShadow"
              ],
              resources: ['*'],
              effect: iam.Effect.ALLOW
            })
          ]
        })
      }
    })
    
    let unauth_role = new iam.Role(this, 'freertosUnauthRole', {
      assumedBy: new iam.FederatedPrincipal('cognito-identity.amazonaws.com', {
        'ForAnyValue:StringLike': {
          "cognito-identity.amazonaws.com:amr": "authenticated"
        }
      }),
    })

    new cognito.CfnIdentityPoolRoleAttachment(this, 'authrole', {
      identityPoolId: identitypool.ref,
      roles: {
        'authenticated': auth_role.roleArn,
        'unauthenticated': unauth_role.roleArn,
      }
    })

    new cdk.CfnOutput(this, 'identitypool', {
      value: identitypool.ref,
      description: 'IdentityPoolId'
    })

    new cdk.CfnOutput(this, 'userpool', {
      value: userpool.userPoolId,
      description: 'UserPoolId'
    })

    new cdk.CfnOutput(this, 'userpoolclientid', {
      value: appClient.userPoolClientId,
      description: 'UserPoolClientId'
    })

    new cdk.CfnOutput(this, 'userpoolclientsecret', {
      value: `https://${this.region}.console.aws.amazon.com/cognito/users/?region=${this.region}#/pool/${userpool.userPoolId}/clients`,
      description: 'UserPoolClientSecretURL - follow link to get secret'
    })


    // The code that defines your stack goes here
  }
}
