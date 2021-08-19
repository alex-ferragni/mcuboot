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

#include "hash/stm32h753_sha256_glue.h"
#include "hash/stm32h753_sha256_types.h"
#include "hal/hal_hash.h"
#include <string.h>

void stm32h753_sha256_init(){
	hash_sha256_init();
}

int stm32h753_sha256_update(const void *data, uint32_t data_len){
	return hash_sha256_update((uint32_t*) data, data_len);
}

int stm32h753_sha256_finish(uint8_t *output){
	return hash_sha256_finish((uint32_t*) output);
}