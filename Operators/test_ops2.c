int main() {
int x = 5, y = 9, z;
z = x++ ; y = ++z - x++ ; x = y-- - --z ;
printf("%d %d %d\n", x, y, z);
}
