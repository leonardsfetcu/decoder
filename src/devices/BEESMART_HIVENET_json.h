#include "common_props.h"

const char* _BEESMART_HIVENET_json = "{\"brand\":\"BeeSmart\",\"model\":\"HiveNet Sensor\",\"model_id\":\"HNS01THB\",\"tag\":\"0205\",\"condition\":[\"name\",\"index\",0,\"BeeSmart\",\"&\",\"manufacturerdata\",\"=\",24],\"properties\":{\"tempc\":{\"decoder\":[\"value_from_hex_data\",\"manufacturerdata\",2,4,true,true],\"post_proc\":[\"/\",100]},\"hum\":{\"decoder\":[\"value_from_hex_data\",\"manufacturerdata\",6,4,true,false],\"post_proc\":[\"/\",100]},\"vbatt\":{\"decoder\":[\"value_from_hex_data\",\"manufacturerdata\",18,4,true,false]}}}";
/* R""""(
{
   "brand":"BeeSmart",
   "model":"HiveNet Sensor",
   "model_id":"HNS01THB",
   "tag":"0205",
   "condition":["name", "index", 0, "BeeSmart", "&", "manufacturerdata", "=", 24],
   "properties":{
      "tempc":{
         "decoder":["value_from_hex_data", "manufacturerdata", 2, 4, true, true],
         "post_proc":["/", 100]
      },
      "hum":{
         "decoder":["value_from_hex_data", "manufacturerdata", 6, 4, true, false],
         "post_proc":["/", 100]
      },
      "vbatt":{
         "decoder":["value_from_hex_data", "manufacturerdata", 18, 4, true, false]
      }
   }
})"""";*/

const char* _BEESMART_HIVENET_json_props = "{\"properties\":{\"tempc\":{\"unit\":\"°C\",\"name\":\"temperature\"},\"hum\":{\"unit\":\"%\",\"name\":\"humidity\"},\"vbatt\":{\"unit\":\"mV\",\"name\":\"voltage\"}}}";
/* R""""(
{
   "properties":{
      "tempc":{
         "unit":"°C",
         "name":"temperature"
      },
      "hum":{
         "unit":"%",
         "name":"humidity"
      },
      "vbatt":{
         "unit":"mV",
         "name":"voltage"
      }
   }
})"""";*/
