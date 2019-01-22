#include<cstdio>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int main()
{
	int n, m;
	vector<vector<int>> graph;
	vector<int> emp;
	vector<int> indeg, outdeg;
	priority_queue<pair<double, int>> pq;
	pair<double, int> cur, cur2;
	int input1, input2;
	int i, j;
	int ptr;
	double val, add, add2;
	int v;
	vector<char*> steps;
	char *buf;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);

		indeg.push_back(0);

		outdeg.push_back(0);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input2].push_back(input1);

		outdeg[input1]++;

		indeg[input2]++;
	}

	for (i = 1; i <= n; i++)
	{
		if (outdeg[i] == 0)
		{
			val = 0.0;

			for (j = 0; j < graph[i].size(); j++)
			{
				if (outdeg[graph[i][j]] == 1)
				{
					val += 1.0;
				}

				else
				{
					add = 1;
					add /= ((double)outdeg[graph[i][j]]);
					add /= ((double)outdeg[graph[i][j]]);
					val += add;
				}

				val *= 10.0;

				add2 = 1;
				add2 *= ((double)indeg[graph[i][j]]);
				val += add2;
			}

			pq.push(pair<double, int>(val, i));
		}
	}

	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();

		buf = new char[100];

		ptr = 0;

		if (!pq.empty())
		{
			cur2 = pq.top();
			pq.pop();

			ptr += sprintf(buf + ptr, "2 %d ", cur2.second);

			for (i = 0; i < graph[cur2.second].size(); i++)
			{
				if (--outdeg[graph[cur2.second][i]] == 0)
				{
					val = 0.0;

					v = graph[cur2.second][i];

					for (j = 0; j < graph[v].size(); j++)
					{
						if (outdeg[graph[v][j]] == 1)
						{
							val += 1.0;
						}

						else
						{
							add = 1;
							add /= ((double)outdeg[graph[v][j]]);
							add /= ((double)outdeg[graph[v][j]]);
							val += add;
						}

						val *= 10.0;

						add2 = 1;
						add2 *= ((double)indeg[graph[v][j]]);
						val += add2;
					}

					pq.push(pair<double, int>(val, graph[cur2.second][i]));
				}
			}
		}

		else
		{
			ptr += sprintf(buf + ptr, "1 ");
		}

		ptr += sprintf(buf + ptr, "%d\n", cur.second);

		for (i = 0; i < graph[cur.second].size(); i++)
		{
			if (--outdeg[graph[cur.second][i]] == 0)
			{
				val = 0.0;

				v = graph[cur.second][i];

				for (j = 0; j < graph[v].size(); j++)
				{
					if (outdeg[graph[v][j]] == 1)
					{
						val += 1.0;
					}

					else
					{
						add = 1;
						add /= ((double)outdeg[graph[v][j]]);
						add /= ((double)outdeg[graph[v][j]]);
						val += add;
					}

					val *= 10.0;

					add2 = 1;
					add2 *= ((double)indeg[graph[v][j]]);
					val += add2;
				}

				pq.push(pair<double, int>(val, graph[cur.second][i]));
			}
		}

		steps.push_back(buf);
	}

	printf("%d\n", steps.size());

	for (i = 0; i < steps.size(); i++)
	{
		printf("%s", steps[i]);
	}

	return 0;
}