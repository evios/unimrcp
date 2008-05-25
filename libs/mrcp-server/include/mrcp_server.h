/*
 * Copyright 2008 Arsen Chaloyan
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

#ifndef __MRCP_SERVER_H__
#define __MRCP_SERVER_H__

/**
 * @file mrcp_server.h
 * @brief MRCP Server
 */ 

#include "mrcp_sig_types.h"
#include "apt_task.h"

APT_BEGIN_EXTERN_C

/** Opaque MRCP server declaration */
typedef struct mrcp_server_t mrcp_server_t;

/**
 * Create MRCP server instance.
 * @return the created server instance
 */
MRCP_DECLARE(mrcp_server_t*) mrcp_server_create();

/**
 * Start message processing loop.
 * @param server the MRCP server to start
 * @return the created server instance
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_start(mrcp_server_t *server);

/**
 * Shutdown message processing loop.
 * @param server the MRCP server to shutdown
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_shutdown(mrcp_server_t *server);

/**
 * Destroy MRCP server.
 * @param server the MRCP server to destroy
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_destroy(mrcp_server_t *server);


/**
 * Register MRCP resource factory.
 * @param server the MRCP server to set resource factory for
 * @param resource_factory the resource factory to set
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_resource_factory_register(mrcp_server_t *server, mrcp_resource_factory_t *resource_factory);

/**
 * Register media engine.
 * @param server the MRCP server to set media engine for
 * @param media_engine the media engine to set
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_media_engine_register(mrcp_server_t *server, apt_task_t *media_engine);

/**
 * Register MRCP signaling agent.
 * @param server the MRCP server to set signaling agent for
 * @param signaling_agent the signaling agent to set
 */
MRCP_DECLARE(apt_bool_t) mrcp_server_signaling_agent_register(mrcp_server_t *server, mrcp_sig_agent_t *signaling_agent);

/**
 * Get memory pool.
 * @param server the MRCP server to get memory pool from
 */
MRCP_DECLARE(apr_pool_t*) mrcp_server_memory_pool_get(mrcp_server_t *server);


APT_END_EXTERN_C

#endif /*__MRCP_SERVER_H__*/