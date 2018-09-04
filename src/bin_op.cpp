#include <iostream>
#include <string>
#include <vector>
#include <math.h>

std::string oct_to_bin(unsigned char nbr){
    std::string result = "";
    for (unsigned int i = 0; i < 8; i++)
        result += std::to_string((nbr >> (7 - i) & 1));
    return (result);
}

std::vector<unsigned char> add_bin(unsigned char img_pixel[4], unsigned char msg_char){
    std::vector<unsigned char> result;
    for (unsigned int i = 0; i < 4; i++){
        result.push_back((img_pixel[i] & 252) | ((msg_char >> ((3 - i) * 2)) & 3));
        std::cout << "Msg[" << i << "]: " << oct_to_bin((msg_char >> ((3 - i) * 2)) & 3) << std::endl;
    }
    return (result);
}

int main(int argc, char **argv){
    unsigned char img_pixel[4] = {56, 13, 190, 254};
    std::vector<unsigned char> result;
    unsigned char msg_char = 'g';
    for (unsigned int i = 0; i < 4; i++){
        std::cout << oct_to_bin(img_pixel[i]) << std::endl;
    }
    std::cout << "====================" << std::endl;
    std::cout << oct_to_bin(msg_char) << std::endl;
    std::cout << "====================" << std::endl;
    result = add_bin(img_pixel, msg_char);
    for (unsigned int i = 0; i < 4; i++){
        std::cout << oct_to_bin(result[i]) << std::endl;
    }
    
    return (0);
}
