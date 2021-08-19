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

#include "cryp/stm32h753_aes_ctr_glue.h"
#include "cryp/stm32h753_aes_ctr_types.h"
#include "hal/hal_cryp.h"
#include "mcuboot_config/mcuboot_assert.h"
#include <string.h>

/* 
 * Initializes hw for a new AES-CTR encryption/decryption
 */
void stm32h753_aes_ctr_init(){
	cryp_aes_ctr_init();
}

/* 
 * Abort any ongoing AES-CTR encryption/decryption
 */
void stm32h753_aes_ctr_drop(){
	cryp_aes_ctr_drop();
}

/* 
 * Configures hw to use the given key
 */
int stm32h753_aes_ctr_set_key(bootutil_aes_ctr_context *ctx, const uint8_t *k, uint32_t length){

	ASSERT(length == 16);

	ASSERT(ctx != 0);
	ASSERT(k != 0);
	memcpy(ctx->key, k, length);

	return 0;
}

/* 
 * Performs AES-CTR encryption using the currently setup key
 */
int stm32h753_aes_ctr_encrypt(bootutil_aes_ctr_context *ctx, uint8_t *counter, const uint8_t *in, uint32_t inlen, uint32_t blk_off, uint8_t *out){
	//only implemented for blk_off == 0, as MCUboot only passes 0 as argument
	//(as time of implementing this project)
	ASSERT(blk_off == 0);
	//only supports full blocks for now (againt, MCUboot only passe full blocks)
	ASSERT(inlen%16 == 0);
	ASSERT(ctx != 0);
	
	//multiple another key might have been set in-between, make sure we use the right one
	if (cryp_aes_ctr_set_key(ctx->key) != 0){
		return -1;
	}

	//"counter" is a 16 bytes array, the 12 first are set to 0, the 4 last form the actual counter
	if (cryp_aes_ctr_encrypt(((uint32_t*)counter)[3], in, inlen, out) != 0){
		return -1;
	}

	return 0;
}