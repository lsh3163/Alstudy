#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;
    int order;
};

bool cmp(const Person &u, const Person &v) {
	if(u.age < v.age) return true;
	if(u.age == v.age){
		return u.order < v.order;
	}
	return false;
}
int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].age >> a[i].name;
        a[i].order = i;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << a[i].age << ' ' << a[i].name << '\n';
    }

    return 0;
}
