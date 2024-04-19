/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ciot.h"
#include "ciot_log.h"
#include "ciot_sys.h"
#include "ciot_mqttc.h"

#include "hg_tcp_msg_types.h"

static const char *TAG = "main";

typedef enum app_iface
{
    APP_IFACE_SYS,
    APP_IFACE_MQTTC,
    APP_IFACE_COUNT,
} app_iface_t;

typedef struct app
{
    ciot_t ciot;
    ciot_sys_t sys;
    ciot_mqttc_t mqttc;
    ciot_iface_t *ifaces[APP_IFACE_COUNT];
    void *cfgs[APP_IFACE_COUNT];
} app_t;

ciot_sys_cfg_t sys_cfg = {};

ciot_mqttc_cfg_t mqttc_cfg = {
    .client_id = "cezar",
     .user = "test_user",
     .pass = "test_user",
    .port = 1883,
    .qos = 0,
    .topics.b2d = "3.0/teste/b2d",
    .topics.d2b = "3.0/teste/d2b",
    .transport = CIOT_MQTT_TRANSPORT_OVER_TCP,
    .url = "mqtt://44.213.195.220:1883",
};

static void app_start(app_t *app);

static ciot_err_t app_event_handler(ciot_iface_t *iface, ciot_iface_event_t *event, void *args);


void app_main()
{
    app_t app;

    app_start(&app);

    while (true)
    {
        ciot_sys_task(app.sys);
    }
}

static void app_start(app_t *self)
{

    CIOT_LOGI(TAG, "App is initializing...", "");
    self->ciot = ciot_new();
    self->sys = ciot_sys_new(CIOT_HANDLE);
    self->mqttc = ciot_mqttc_new(CIOT_HANDLE);

    self->ifaces[APP_IFACE_SYS] = (ciot_iface_t*)self->sys;
    self->ifaces[APP_IFACE_MQTTC] = (ciot_iface_t*)self->mqttc;

    self->cfgs[APP_IFACE_SYS] = &sys_cfg;
    self->cfgs[APP_IFACE_MQTTC] = &mqttc_cfg;

    ciot_register_event(self->ciot, app_event_handler, self);

    ciot_cfg_t ciot_cfg = {
        .ifaces = self->ifaces,
        .cfgs = (void**)self->cfgs,
        .count = APP_IFACE_COUNT
    };
    ciot_start(self->ciot, &ciot_cfg);
}

static ciot_err_t app_event_handler(ciot_iface_t *iface, ciot_iface_event_t *event, void *args)
{
    app_t *app = (app_t*)args;
    ciot_mqttc_event_data_t* aux;
    hg_tcp_msg_prov_available_t* aux2;
    int goiaba = sizeof(aux2->sys);

    if(iface->info.type == CIOT_IFACE_TYPE_MQTT && event->id == CIOT_IFACE_EVENT_STARTED)
    {
        CIOT_LOGI(TAG, "Mqtt conectado!");
        ciot_iface_send_data(iface, "Hello World!", 12);
        ciot_mqttc_subscribe(app->mqttc, "3.0/#", 0);
    }
    if(iface->info.type == CIOT_IFACE_TYPE_MQTT && event->id == CIOT_IFACE_EVENT_DATA){
        CIOT_LOGI(TAG, "dado recebido!");

/*
        aux = event->data;

        aux2 = aux->payload.ptr;

*/

        CIOT_LOGI(TAG, "dado interpretado!");
    }


    return CIOT_ERR_NOT_IMPLEMENTED;
}