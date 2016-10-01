#include "Converter.hpp"

int main(){
    Converter* convertidor = new Converter("Testing/test6.png","Result/test21.txt");
    convertidor->processImage();
    delete convertidor;
    return 0;
}
