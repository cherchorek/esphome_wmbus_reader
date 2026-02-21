import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID

DEPENDENCIES = ["sensor"]

wmbus_ns = cg.esphome_ns.namespace("wmbus_reader")
WMBusReader = wmbus_ns.class_("WMBusReader", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(WMBusReader),
    cv.Required("water_total"): cv.use_id(sensor.Sensor),
    cv.Required("water_rssi"): cv.use_id(sensor.Sensor),
    cv.Required("meter_id"): cv.hex_uint32_t,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add(var.set_water_total(config["water_total"]))
    cg.add(var.set_water_rssi(config["water_rssi"]))
    cg.add(var.set_meter_id(config["meter_id"]))