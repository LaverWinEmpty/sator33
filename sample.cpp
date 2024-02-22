#include "iostream"
#include "sator33.hpp"

int main()
{
    cout << "3 x 3 sator square maker" << std::endl;
    cout << "Please enter three letters" << std::endl;

    setlocale(LC_ALL, "KOR");

    Sator33 maker;

    const wstring END_KEYWORD      = L"exit";
    const size_t  END_KEYWORD_SIZE = END_KEYWORD.size();

    wcout << L"End keyword: " << END_KEYWORD << L"\n" << endl;

    bool isEnd = false;

    // loop
    while(!isEnd) {
        // loop
        while(true) {
            wstring str;
            cout << "Input: ";
            wcin >> str;

            // check
            if(str.size() == END_KEYWORD_SIZE) {
                if(!str.compare(END_KEYWORD)) {
                    break;
                }
            }

            // set
            Sator33::EResult res = maker.Input(str);

            // check
            switch(res) {
            case Sator33::OK: wcout << L"current string amount is " << maker.GetWordsCount() << endl; break;
            case Sator33::INVALID: wcout << str << L" is not 3 words" << endl; break;
            case Sator33::DUPLICATED: wcout << str << L"is duplicate" << endl; break;
            }
        }

        // make
        maker.Make();

        // print
        cout << endl;
        size_t size = maker.GetResultCount();
        for(int i = 0; i < size; ++i) {
            auto v = maker.GetResult(i);

            wcout << v[0] << "\n" << v[1] << "\n" << v[2] << "\n" << endl;
        }

        // loop
        while(true) {
            string str;
            cout << "continue? Y/N: ";
            cin >> str;

            char lastLowercase = (str[str.size() - 1]) | 0x20;

            if(lastLowercase == 'y') {
                break;
            }
            if(lastLowercase == 'n') {
                isEnd = true;
                break;
            }
        }
    }

    // end
    printf("Press A Key... ");
    while(getchar() != '\n') {}
    getchar();
}