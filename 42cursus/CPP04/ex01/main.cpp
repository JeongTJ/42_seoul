
int main() {
	F a;
	F b(a);

	delete a;
	delete b;
}
