#include <iostream>
#include <string>
#define PV_NO_IMPORT_SPECS
#include <pv_porcupine.h>

using namespace std;

int main(){
    static const char* ACCESS_KEY = "F3/GRp7wSGgVg3HFj6Lnh+0cmYvIj/FDWlHEu4UcLRUFpmpfJwoGuw==";


    const char *model_file_path = "C:/Users/egora/Desktop/C++Bot/porcupine_params.pv";
    const char *keyword_file_path = "C:/Users/egora/Desktop/C++Bot/jarvis_windows.ppn";
    const float sensitivity = 0.5f;


    pv_porcupine_t *porcupine;


    const pv_status_t status = pv_porcupine_init(
        ACCESS_KEY,
        model_file_path,
        1,
        &keyword_file_path,
        &sensitivity,
        &porcupine);


    extern const int16_t *get_next_audio_frame(void);

    while (true) {
        const int16_t *pcm = get_next_audio_frame();
        int32_t keyword_index;
        const pv_status_t status = pv_porcupine_process(porcupine, pcm, &keyword_index);
        if (status != PV_STATUS_SUCCESS) {
            // error handling logic
        }
        if (keyword_index != -1) {
            cout << "Hello Gitler";
        }
    }

}