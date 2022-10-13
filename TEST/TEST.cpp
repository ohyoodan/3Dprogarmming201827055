#include <iostream>
#include <string>



float a= 1;
bool chk = false;

int Main(void) {
    while (true) {
        if (chk == true) {
            a -= 0.1f;

        }
        else if (chk == false)
        {
            a += 0.1f;
        }

        if (a >= 1.3f && (chk == false)) {
            chk = true;
        }
        else if (a <= 0.7 && (chk == true)) {
            chk = false;
        }
        string b = "FPS : " + to_string(a);
        std::cout << b;
    }
}


