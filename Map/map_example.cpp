#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	///1. 初始化
	map<int, string> mapStudent;
	map<int, string>::iterator iter, beg, end;

	///2. 添加元素
	mapStudent[0] = "student_one";
	mapStudent[1] = "student_two";
	mapStudent[2] = "student_three";
	mapStudent.insert(pair<int, string>(5, "Fear Kubrick"));
	mapStudent.insert(pair<int, string>(2, "Akemi Homura"));
	mapStudent.insert(pair<int, string>(-1, "Eren Jaeger"));
	mapStudent.insert(pair<int, string>(99, "lin"));
	cout << mapStudent.size() << endl;
	cout << endl;

	///3. 遍历
	///可以使用下标访问，但对于不存在的键值，该操作会将此键值加入map!
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	cout << endl;

	///4. 查询
	///可以像3中那样使用下标，但如果该key不在map中，此操作将会插入一个具有该key的新元素
	///用find(key)最好
	iter = mapStudent.find(1);
	if (iter != mapStudent.end())
		cout << iter->second << endl;
	else
		cout << -1 << endl;
	iter = mapStudent.find(6);
	if (iter != mapStudent.end())
		cout << iter->second << endl;
	else
		cout << -1 << endl;
	cout << endl;

	///5. 删除
	///单键删除
	iter = mapStudent.find(1);
	if (iter != mapStudent.end())
		mapStudent.erase(iter);
	cout << mapStudent.size() << endl;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;

	///范围删除
	beg = mapStudent.find(-1);
	end = mapStudent.find(5);
	if (beg != mapStudent.end() && end != mapStudent.end())
		mapStudent.erase(beg, end);///删除beg到end之前的元素，不包括end
		///若想删除end的键值，可以这么写：mapStudent.erase(beg, ++end);
		///或者将上面的改为end = mapStudent.upper_bound(5);
	cout << mapStudent.size() << endl;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	cout << endl;

	///6. 判空与清空
	if (!mapStudent.empty())
		mapStudent.clear();
}
