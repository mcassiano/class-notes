#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv) {

	map<int, bool> jack;
	int n, m, j;

	while (scanf("%d %d", &n, &m) != EOF) {

		if (n == 0 && m == 0)
			break;

		jack.clear();
		int count = 0;
		map<int, bool>::iterator it;

		for (int i = 0; i < n; i++) {
			scanf("%d", &j);
			jack[j] = true;
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &j);

			if ((it = jack.find(j)) != jack.end())
				if (jack[j])
					count += 1;
		}

		printf("%d\n", count);

	}

	return 0;

}