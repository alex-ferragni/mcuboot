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

#ifndef __stm32h753_AES_CTR_GLUE_H__
#define __stm32h753_AES_CTR_GLUE_H__

#include <stdint.h>
#include "cryp/stm32h753_aes_ctr_types.h"

/**
 * @brief Initializes hw for a new AES-CTR encryption/decryption
 */
void stm32h753_aes_ctr_init();

/**
 * @brief Abort any ongoing AES-CTR encryption/decryption
 */
void stm32h753_aes_ctr_drop();

/**
 * @brief Configures hw to use the given key
 *
 * @param ctx The context in which the key will be stored
 * @param k The 16 bytes encryption/decryption key
 * @param length The length of the key, should always be 16
 *
 * @return 0 on success, -1 on error
 */
int stm32h753_aes_ctr_set_key(bootutil_aes_ctr_context *ctx, const uint8_t *k, uint32_t length);

/**
 * @brief Performs AES-CTR encryption using the currently setup key
 *
 * @param ctx The context containing the current key
 * @param counter The block counter of the first block
 * @param in The input data buffer
 * @param inlen The length (in bytes) of the input and output buffers
 * @param blk_off The offset within the block, should always be 0
 * @param out The output data buffer
 *
 * @return 0 on success, -1 on error
 */
int stm32h753_aes_ctr_encrypt(bootutil_aes_ctr_context *ctx, uint8_t *counter, const uint8_t *in, uint32_t inlen, uint32_t blk_off, uint8_t *out);

#endif /* __stm32h753_AES_CTR_GLUE_H__ */