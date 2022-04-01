/*
    api add user api -accept an email
    
    be-friend (email1,email2)
    
    checkfriendship(email1,email2);


map<node,1> checking if the user is registered or not
node email1.friend.append(email2)
node{
    email;
    map<node,bool>friend;
}

befriend(email1,email2){
    //check if the 2email the in the map or not
    //email1.friend.push_back(email2);
    //email2.friend.push_back(email1);
    //in email1 we are adding all it mutual friend in map friend;

}

bool checkfriendship(email1,email5){  //o(1)
    if(email1! in map || email2!in map)
        return false;
    vis[email1]=true; 
    bool check=false;          // 1 5 
    if(map.find(email1.friend[email5])!=map.end()){
        return true;
    }
    return false;
   /* for(auto a: email1.friend){ ///email1  34  3 ->5
      if(!vis[a]) 
        {
            if(email2 ==a){
             return true;
        }
     check= checkfriendship(a,email2)
     if(check)
        break;
        \
    }
    return check;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    string email;
    map<string,node>friends;
};
class friendships{
    public:
        map<string,node>allEmails;
        void addemail(string email1){
            node a;
            a.email=email1;
            if(allEmails.find(email1)!=allEmails.end()){
                cout<<email1<<"is already added"<<endl;
                return;
            }
            allEmails[email1]=a;
        }
        map<string,node> dfs1(string mutual,map<string,node>&res,map<string,bool>visited){
                node *a=&allEmails[mutual];
                for(auto i:a->friends){
                   if(visited.find(i.first)==visited.end())
                   { 
                    visited[i.first]=true;
                    res[i.first]=i.second;
                    dfs1(i.first,res,visited);
                    allEmails[i.first].friends=res;
                   }
                }
        return res;
        }
        void befriend(string email1,string email2){
            if(allEmails.find(email1)==allEmails.end() || allEmails.find(email2)==allEmails.end()){
                cout<<"the email is not add"<<endl;
                return;
            }
            node *a=&allEmails[email1];
            node *b=&allEmails[email2];
            a->friends[email2]=*b;
            b->friends[email1]=*a;
            map<string,node> res;
            map<string,bool>visited;
            allEmails[email1].friends=dfs1(email1,res,visited);
            allEmails[email2].friends=dfs1(email2,res,visited);
            // for(auto i:res){
            //     cout<<i.first<<" ";
            // }
           // cout<<endl;
          
        }

        void checkfriendship(string email1,string email2){  //o(1)
            if(allEmails.find(email1)==allEmails.end() || allEmails.find(email2)==allEmails.end()){
                cout<<"the email is not add";
                return;
            }
            node a=allEmails[email1];
            // for(auto i:a.friends){
            //     cout<<i.first<<" ";
            // }
            if(a.friends.find(email2)!=a.friends.end())
               {
                cout<<email2<<" is a friend of "<<email1<<endl; 
                }
            else{
                cout<<email2<<" is not a friend of "<<email1<<endl; 
            }
        }
        void checkfriend(string email1){
            node a=allEmails[email1];
            for(auto i:a.friends){
                cout<<i.first<<" ";
            }

        }
};

int main(){
    friendships f;
    f.addemail("uddipta");
    f.addemail("dubey");
    f.addemail("rishav");
    f.addemail("sid");
    f.addemail("dana");
    f.addemail("ritwik");
    f.addemail("bhavy");

    f.befriend("uddipta","dubey");
    f.befriend("uddipta","dana");
    f.befriend("ritwik","rishav");
    f.befriend("rishav","sid");

    f.checkfriendship("uddipta","dubey");
    f.checkfriendship("uddipta","rishava");
   // f.checkfriend("uddipta");
    //f.show();

}