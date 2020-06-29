#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::string base64_encode(unsigned char const* buf, unsigned int bufLen);
std::vector<unsigned char> base64_decode(std::string const&);
using namespace std;

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

//reddit did not allow to paste the string 
std::vector<unsigned char> base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::vector<unsigned char> ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
          ret.push_back(char_array_3[i]);
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
  }

  return ret;
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;
}

std::string saveImage(std::string base64, std::string folder, std::string name) {   
    std::size_t image_type_initial = base64.find('/');
    std::size_t image_type_end = base64.find(';');
    std::string image_type = base64.substr(image_type_initial + 1, image_type_end - image_type_initial - 1);

    std::size_t comma_pos = base64.find(',');
    std::string image_data_str = base64.substr(comma_pos + 1);
    const char* image_data = image_data_str.c_str();

    std::string image_file_name = "../";
    image_file_name.append(folder);
    image_file_name.append(name);
    image_file_name.append(".");
    image_file_name.append(image_type);

    std::string return_image_filename = "";
    return_image_filename.append(folder);
    return_image_filename.append(name);
    return_image_filename.append(".");
    return_image_filename.append(image_type);
    
    //std::cout << "Image name " << image_file_name << '\n';

    std::vector<unsigned char> decodedData = base64_decode(image_data);
    std::ofstream myfile(image_file_name);
    char* d=(char*)&decodedData[0];
    myfile.write(d, decodedData.size());
    myfile.close();

    return return_image_filename;
}

std::string image_to_string(std::string filename) {
  std::ostringstream ostrm;   

  //std::cout << "Path to image " << filename << '\n';
  
  std::ifstream imgfile("../" + filename, ios::binary);
  ostrm << imgfile.rdbuf();

  std::string encondedImage( ostrm.str() );
  return encondedImage;
}