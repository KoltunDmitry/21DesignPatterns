// Фасад — это структурный паттерн проектирования,
// который предоставляет простой интерфейс к сложной системе классов, библиотеке или фреймворку.
#include <iostream>
#include <string>
#include <algorithm>
//#include <string_view>

using namespace std;

class Image{
public:
    Image(string filename): filename(filename) {}
    string getFilename() const {
        return filename;
    }
    void setFilename(const string& str) {
        filename = str;
    }
private:
    string filename;
};

//some difficult code
class PNGConverter{};

class JPEGConverter{};


//Facade
class Converter{
public:
    Image convert(Image& image, const string& newFormat){
        string format = getFormat(image);
        cout << "formating " << format << " to " << newFormat << endl;
        if(format == "png"){
            //...
        }
        else if(format == "jpeg"){
            //...
        }
        else{
            //...
        }
        
        return image;

    }
private:
    string getFormat(const Image& file) {
        const string& filename = file.getFilename();
        auto pos = filename.find_last_of('.');
        return filename.substr(pos + 1, filename.npos);
    }
};

int main(){
    Converter converter;
    Image pngImage("image.png");
    converter.convert(pngImage, "jpeg");
}