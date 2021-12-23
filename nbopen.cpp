#include <string>
#include <locale>

static wchar_t* charToWChar(const char* text)
{
    size_t size = strlen(text) + 1;
    wchar_t* wText = new wchar_t[size];

    size_t outSize;
    mbstowcs_s(&outSize, wText, size, text, size - 1);

    return wText;
}

int main(int argc, char* argv[])
{
    std::locale::global(std::locale(""));

    if (argc == 2) {
        std::wstring file_name = charToWChar(argv[1]);
        std::wstring command = L"jupyter notebook \"" + file_name + L'\"';

        _wsystem(command.c_str());
    }
}