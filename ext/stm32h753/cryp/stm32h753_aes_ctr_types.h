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

#ifndef __stm32h753_AES_CTR_TYPES_H__
#define __stm32h753_AES_CTR_TYPES_H__

#include <stdint.h>

#define BOOTUTIL_CRYPTO_AES_CTR_KEY_SIZE (16)
#define BOOTUTIL_CRYPTO_AES_CTR_BLOCK_SIZE (16)

typedef struct{
	uint8_t key[BOOTUTIL_CRYPTO_AES_CTR_KEY_SIZE];
} bootutil_aes_ctr_context;

#endif /* __stm32h753_AES_CTR_TYPES_H__ */