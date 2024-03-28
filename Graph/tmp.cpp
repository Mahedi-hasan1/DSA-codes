#include<bits/stdc++.h>
using namespace std;
int main(){
	
	string tmp ;
	getline(cin, tmp) ;
	map<string, bool> verFeature;
	
	string feature = " ";
	for(int i=1 ; i<tmp.size() ; i++ ){
		if(tmp[i] == ',' || tmp[i] == ']'){
			verFeature[feature] = 1;
			feature = "";
			i++;   // for space
			continue;
    	}
		feature += tmp[i];
	}
	
	int id = 0;
	vector<int> queryID;
	vector<string> add;
	vector<pair<string, string>> modify;
	map<int, vector<pair<string, int>>> query_for_version;
	
	int query_cnt = 0;
	while( getline(cin, tmp)){
		query_cnt++;
		if (tmp.substr(0, 3) == "Add")
		{
			string add_feature = "";
            for (int i = 4; i < tmp.size(); i++)
            {
                if (tmp[i] == ' ')
                    break;
                add_feature += tmp[i];
            }	
          
            add.push_back(add_feature);
			queryID.push_back(0);
		}
		else if (tmp.substr(0, 6) == "Modify")
		{
			string from = "", to = "";
			int i = 7;
			for (; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ') break;
				from += tmp[i];
			}
			++i;
			for(; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ') break;
				to += tmp[i];
			}
           
			modify.push_back({from, to});
			queryID.push_back(1);
		}
		else 
		{
			string check_feature = "";
			int version = 0;
			int i = 14;
			for (; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ')	break;
				int digit = tmp[i] - '0';
				version = version * 10 + digit;
			}
			++i;
			for (; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ') break;
				check_feature += tmp[i];
			}
			query_for_version[version].push_back({check_feature, query_cnt});
			queryID.push_back(2);
		}
	}
	reverse(add.begin(), add.end());
	reverse(modify.begin(), modify.end());
	
	vector<pair<int, bool>> res;
	int cur_version = 1;
	for (auto query : query_for_version[cur_version])
	{
		res.push_back({query.second,  verFeature[query.first]});
	}

	for (int query = 0; query <  queryID.size(); query++)
	{
		if (queryID[query] == 0)
		{
			verFeature[add.back()] = 1;
			add.pop_back();
			++cur_version;
		}
		else if (queryID[query] == 1)
		{
			verFeature[modify.back().first] = 0;
			verFeature[modify.back().second] = 1;
			modify.pop_back();
			++cur_version;
		}
		else  continue;
		
		for (auto check_current :  query_for_version[cur_version])
		{
			res.push_back({check_current.second,  verFeature[check_current.first]});

		}
}
sort(res.begin(), res.end());
for (int i = 0; i < res.size(); i++)
{
	if (res[i].second) cout << "Yes\n";
	else cout << "No\n";
}
}
