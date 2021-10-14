#include <iostream>
#include <cstring>

using namespace std;
char** copy_replace(const char* sentences[], const char original_char, const
    char new_char, int num_of_sentence) {
    char* buffer; // array
    char** container = new char* [num_of_sentence];
    for (int i = 0; i < num_of_sentence; i++) {
        //std::cout << "strlen sentences : " << strlen(sentences[i]) << std::endl; //test code
        buffer = new char[strlen(sentences[i])];
        for (int j = 0; j < strlen(sentences[i]); j++) {
            if (*(sentences[i] + j) == original_char) { //sentences[i] -> hello world를 가르키는 포인터 -
                buffer[j] = new_char;
            }
            else {  
                buffer[j] = *(sentences[i] + j);
            }
        }
        container[i] = buffer;
        

    }
    return container;
    //return container;
}


int main() {
    const char* sentence[] = { "Hello World", "Hi World", "Heyo World" };
    int num_of_sentence = 3;
    char** p_result = copy_replace(sentence, 'o', 'x', num_of_sentence);
    cout << sentence[0] << endl;
    cout << sentence[1] << endl;
    cout << sentence[2] << endl;
    cout << p_result[0] << endl;
    cout << p_result[1] << endl;
    cout << p_result[2] << endl;
    //Implement memory deallocation (Optional)
}