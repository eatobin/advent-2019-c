#include <iostream>
#include <string>
#include <vector>

/*
procedure generate(n : integer, A : array of any):
    if n = 1 then
          output(A)
    else
        for i := 0; i < n - 1; i += 1 do
            generate(n - 1, A)
            if n is even then
                swap(A[i], A[n-1])
            else
                swap(A[0], A[n-1])
            end if
        end for
        generate(n - 1, A)
    end if
*/

template <typename T>
void output(std::vector<T>& A) {
    for (auto const& a : A) std::cout << a << ' ';
    std::cout << '\n';
}

template <typename T>
void generate(size_t n, std::vector<T>& A) {
    if (n == 1) 
        output(A);
    else {
        for (size_t i = 0; i < n - 1; ++i) {
            generate(n - 1, A);
            if (n % 2 == 0)
                std::swap(A[i], A[n-1]);
            else
                std::swap(A[0], A[n-1]);
        }
        generate(n - 1, A);
    }
}
        
int main(int argc, char** argv) {
    std::vector<const char*> A(argv + 1, argv + argc);
    generate(A.size(), A);
    return 0;
}
