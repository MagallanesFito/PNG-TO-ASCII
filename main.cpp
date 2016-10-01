#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
using namespace std;

const int Caracteres_Size = 39;

string Caracteres[] = {"Q", "N","%","Q", "g", "m", "$", "B", "D", "R",
"#", "8", "d", "O", "b", "U", "A", "q", "h", "G", "p" ,"X", "k", "u", "n", "x","c", "/","*", "+" ,";", "^", "=", " ´" ,":", " _", " .", " `", " "};
Color actual;

int main(){
    Image Foto;
    Foto.loadFromFile(""); 
    Vector2u Dimensiones = Foto.getSize();

    ofstream resultado;

    resultado.open(""); // a .txt file

    for(int i=0;i<=Dimensiones.y;i++){
        for(int j=0;j<=Dimensiones.x;j++){
            actual = Foto.getPixel(j,i);
            float GreyScale = (actual.r + actual.g + actual.b)/3;
            int nivelSaturacion = (int)((GreyScale/255)*(Caracteres_Size-1));
            resultado << Caracteres[nivelSaturacion] << "  ";
        }
        resultado << "\n";
    }
    resultado.close();
    return 0;
}
