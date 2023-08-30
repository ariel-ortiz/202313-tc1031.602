int main()
{
    int x = 0;
    // int* p = nullptr;
    int* p = &x;
    // int* p = reinterpret_cast<int*>(1000);
    *p = 5;
}
