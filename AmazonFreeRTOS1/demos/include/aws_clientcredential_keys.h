/*
 * Amazon FreeRTOS V201906.00 Major
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

/*
 * PEM-encoded client certificate
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWTCCAkGgAwIBAgIUV/vOREy7FnzRO7aNsMivBIgv6FYwDQYJKoZIhvcNAQEL\n"\
"BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n"\
"SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIwMDIxNzE1Mzk1\n"\
"NVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n"\
"ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANxXw+/EOPR5bDurysd+\n"\
"WiwTV5b4X+7B/BWu5Cll2g7qkTZjdJkHoQ/xb3aN7KuqxUxvdwfysR9T4JGfMsJn\n"\
"TDySec1H1u0AY5Sz8k0ESQocXm/4t0l8wHA2jaiI7M01EvvSXNpOZmSQi61insFT\n"\
"Wro43qmJXb9D7t5ZPPxPdUUTiCgpFZgPYU4QKrki/KfmYTrMFh3wFbLD5CXtlGHH\n"\
"8ibDHnaR2piEf3TjRPmStDocTuOG/yNff5DE/mbdkQqNQLT6UxhfXoDUZc2bKurH\n"\
"FxDyOnCB29jfP3yqdHJ+Mk2de3TqcfQW6crcZ0Li94C5gqg1c17+GJXH4uDh8+tu\n"\
"WbcCAwEAAaNgMF4wHwYDVR0jBBgwFoAUUAZZj4IIXvzPwIWlrSwbvLE5hQYwHQYD\n"\
"VR0OBBYEFJ9DhoM04mGNZzXD+wSKujIWmdTyMAwGA1UdEwEB/wQCMAAwDgYDVR0P\n"\
"AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQB9bBjULnvF0wB4wXtO0VlnWIuV\n"\
"izWllwY23sDezChNs0j88Kf5bsjhpjE4WtAVo1pdLVk4vdk0BXtPrznliLxTRNe2\n"\
"AcP0jdZeSBP462ZlmPn7AGrGPPqF8afJ9ERsTXkYRT0CdDYdGeC55g89onaIxIAV\n"\
"gD+oLhN8/d66wnbkX6gAi99EYN24uFZFqkYntecPpSwXTfnT770y6Zow2C8H45Vy\n"\
"JHTBOME6VW6AE48KAe3VO0fX2OxR8DKG9e7dBUicdZYtgodpjs7JMebgqFnd7X0T\n"\
"H72Stluv/jbagfSMgTbUE6dbqaZvvJbXBYUX7a4iV9JRazV80cElKa13sWpG\n"\
"-----END CERTIFICATE-----\n"

/*
 * PEM-encoded issuer certificate for AWS IoT Just In Time Registration (JITR).
 * This is required if you're using JITR, since the issuer (Certificate 
 * Authority) of the client certificate is used by the server for routing the 
 * device's initial request. (The device client certificate must always be 
 * sent as well.) For more information about JITR, see:
 *  https://docs.aws.amazon.com/iot/latest/developerguide/jit-provisioning.html, 
 *  https://aws.amazon.com/blogs/iot/just-in-time-registration-of-device-certificates-on-aws-iot/.
 *
 * If you're not using JITR, set below to NULL.
 * 
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  NULL

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----\n"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEowIBAAKCAQEA3FfD78Q49HlsO6vKx35aLBNXlvhf7sH8Fa7kKWXaDuqRNmN0\n"\
"mQehD/Fvdo3sq6rFTG93B/KxH1PgkZ8ywmdMPJJ5zUfW7QBjlLPyTQRJChxeb/i3\n"\
"SXzAcDaNqIjszTUS+9Jc2k5mZJCLrWKewVNaujjeqYldv0Pu3lk8/E91RROIKCkV\n"\
"mA9hThAquSL8p+ZhOswWHfAVssPkJe2UYcfyJsMedpHamIR/dONE+ZK0OhxO44b/\n"\
"I19/kMT+Zt2RCo1AtPpTGF9egNRlzZsq6scXEPI6cIHb2N8/fKp0cn4yTZ17dOpx\n"\
"9BbpytxnQuL3gLmCqDVzXv4Ylcfi4OHz625ZtwIDAQABAoIBAESWTTdlLRVsdnRc\n"\
"lVJj0k3F943W4oW/fGiDeCIqwiXCflEfxDueVFRSIxAUPYdyMNgKGlMvCFNoGI87\n"\
"ruE0plZ0gdWUdyJu7JBtMw8mNlYfXoYcNXF6k6xaTt4XQR7fVnlskdqibN0A4Xmn\n"\
"KSOkfqlY6nZ7e+L9km1D+efQFADb77n4amE2fJVilmLxzmyLVP2pxH68zVa2P4EZ\n"\
"i1AbSnoRkTS3OA4J437cO04iSAL4Ua6R9Ph6qVL8Wsj6sm8OKRwA7P/6yAKHJYc7\n"\
"1hravfeA+oVLKusqKs9Uhv6vlez96d/AtD0XHxKlJhpmX23sU0cYgPxPK9plfozj\n"\
"W2wXxQECgYEA7cRtnjhuRvZYvHmVKPjLUaKJmh+oacNORcetW/R2wO37MKo7KoMo\n"\
"Vl+S2qBy4fg6CDP1O65RHRQsQyVjOJVipGl7QbU9kpKAL09arI4n65+YKKuA/0P4\n"\
"LTICKcPtLOqRfvwcd9HviX7cu8Zqwm7ruk5BLPW11iflmwI1OyquaQkCgYEA7T1H\n"\
"wov95JWRiRV8vjiFQa2O9MI6q31ec07gsS2V7bDmTn9VH0CBFeYiG4K3iYHuEGM5\n"\
"xonxP5RrLnBkhIICWeiVpMBmKe6KUtL3PaATHMHhK/5bNkC1zefhPC9jLzFnqJLG\n"\
"GK4ooQcTo3XjTYLmD/0LQ4o1e+8sDp3MI/qJHL8CgYBr45gCFYUkuh/l1h2y68IG\n"\
"lwRtZTQcWb0ouMSXV0STouk6WeRjFAS3vMJ8ZhX7J5HdqwX6QM0Zrs+u4EY3pMGP\n"\
"7TU6yazY15VG4nE4n4DJ0C9RNRFhw0vX5jtJDFiQ6xd+UZPxYteYwnIS2qQS+hYJ\n"\
"Af1dE1mhhZUQU14oLOPbUQKBgF0Qlg72ddHu7pmVKUtBxtyd5h+T9goB80ROpAw9\n"\
"Mrx8kcwnXVAWMM1TavvZyoARzT72fdqpkE79vRIJmxT0H1H/0HxB0ZIPdonJIp41\n"\
"Jmo4kEl+zW858Vfl59CBUmpX+i8B7N4Pq/aHXSfZfiKRAAkznfCPzi1hBKpzMnrG\n"\
"tHTnAoGBANYm7tAdd5HoilVRApqV2dak/XD7ogJU3jLLiVapvMWq2EZeJU9RAzos\n"\
"B9ZMHLNKj1vVAJGke2hJ816ioyd1hsnLwhNqoHiBHMj+wwWa3xEUCJS5emSZpduE\n"\
"XmdLY4fuukdTd9GOdzdQZEZbhfdyLoKM/eASyFI3+Nsz9sVfkk0Z\n"\
"-----END RSA PRIVATE KEY-----\n"


#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
