/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2021 CSEM SA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __stm32h753_HMAC_SHA256_GLUE_H__
#define __stm32h753_HMAC_SHA256_GLUE_H__

#include <stdint.h>
#include "hash/stm32h753_hmac_sha256_types.h"

void stm32h753_hmac_sha256_init(bootutil_hmac_sha256_context *ctx);
int stm32h753_hmac_sha256_update(bootutil_hmac_sha256_context *ctx, const void *data, uint32_t data_len);
int stm32h753_hmac_sha256_final(bootutil_hmac_sha256_context *ctx, uint8_t *tag, unsigned int taglen);
int stm32h753_hmac_sha256_set_key(bootutil_hmac_sha256_context *ctx, const uint8_t *key, unsigned int key_size);

#endif /* __stm32h753_HMAC_SHA256_GLUE_H__ */