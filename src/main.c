#include <cjson/cJSON.h>
#include <stdio.h>
#include <hellors.h>

int main(int argc, char *argv[]) {
  cJSON *json = cJSON_CreateObject();
  if (!json) {
    return 1;
  }
  if (!cJSON_AddStringToObject(json, "key", "value")) {
    cJSON_Delete(json);
    return 1;
  }
  printf("%s\n", cJSON_Print(json));
  cJSON_Delete(json);
  hello();
  return 0;
}
