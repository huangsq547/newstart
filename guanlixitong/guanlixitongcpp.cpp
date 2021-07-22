#include<iostream>
#include<memory>
#include<vector>
using namespace std;
class club;
class student
{
	friend club;
public:
	void setname(string name);
	void setid(int id);
	int show()
	{
		return m_id;
	}
	string showname()
	{
		return m_name;
	}
private:
	string m_name;
	int m_id;
};
void student::setname(string name)
{
	m_name = name;
}
void student::setid(int id)
{
	m_id = id;
}
class club
{
public:
	void setname(string name);
	void joinStudent(const student& rhs);
	void setkind(string kind);
	string show()
	{
		return m_clubName;
	}
	void showstudent()
	{
		int n = m_a.size();
		for (int i = 0; i < n; i++)
		{
			cout << m_a[i].m_id << " " <<m_a[i].m_name<< endl;
		}
	}
	string showkind()
	{
		return m_kind;
	}
	
private:
	vector<student> m_a;
	string m_clubName;
	string m_kind;
};
void club::setkind(string kind)
{
	m_kind = kind;
}
void club::setname(string name)
{
	m_clubName = name;
}
void club::joinStudent(const student& rhs)
{
	m_a.push_back(rhs);
}
int main(void)
{
	string operation;
	vector<shared_ptr<club>> m;
	vector<student> person;
	string name;
	string id;
	int studentid = 10000;
	while (cin>>operation)
	{
		if (operation == "append")
		{
			student a;
			cin >> name;
			a.setname(name);
			a.setid(studentid);
			person.push_back(a);
			++studentid;
	    }
		else if (operation == "create")
		{
			string kind;
			cin >> kind;
			if (kind == "class")
			{
				club k;
				cin >> id;
				k.setname(id);
				k.setkind(kind);
				shared_ptr<club> a(new club(k));
				m.push_back(a);
			}
			else if (kind == "team")
			{
				club k;
				cin >> id;
				k.setname(id);
				k.setkind(kind);
				shared_ptr<club> a(new club(k));
				m.push_back(a);
			}

		}
		else if (operation == "join")
		{
			string elect;//选择加入的是班级还是团队
			string which;//具体是哪个班级或团队
			int who;//具体哪个人加入
			cin >> elect>>which>>who;
			if (elect == "class")
			{
				int i, j, n, k;
				n = m.size();
				k = person.size();
				for (i = 0; i < n; i++)//寻找相应班级
				{
					if (m[i]->show()== which)
					{
						for (j = 0; j < k; j++)//找到要加入的人
						{
							if (person[j].show() == who)
							{
								m[i]->joinStudent(person[j]);
								break;
							}
						}

					}
				}
			}
			else if (elect == "team")
			{
				int i, j, n, k;
				n = m.size();
				k = person.size();
				for (i = 0; i < n; i++)//寻找相应班级
				{
					if (m[i]->show() == which)
					{
						for (j = 0; j < k; j++)//找到要加入的人
						{
							if (person[j].show() == who)
							{
								m[i]->joinStudent(person[j]);
								break;
							}
						}

					}
				}

			}
		}
	}
	cout << "student list:" << endl;
	int x;
	x = person.size();
	for (int i = 0; i < x; i++)//输出学生名单
	{
		cout << person[i].show() << " " << person[i].showname() << endl;
	}
	cout << endl;
	int y;
	y = m.size();
	for (int i = 0; i < y; i++)
	{
		if (m[i]->showkind() == "class")
		{
			cout << "class " << m[i]->show() << ":" << endl;
			m[i]->showstudent();
			cout << endl;
		}
	}
	for (int i = 0; i < y; i++)
	{
		if (m[i]->showkind() == "team")
		{
			cout <<m[i]->show()<<" team" << ":" << endl;
			m[i]->showstudent();
			cout << endl;
		}
	}


	system("pause");
	return 0;
}