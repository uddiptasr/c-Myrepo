/*
    api add user api -accept an email
    
    be-friend (email1,email2)
    
    checkfriendship(email1,email2);


#include<bits/stdc++.h>
using namespace std;
int main(){


}
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

bool checkfriendship(email1,email5){  o(1)
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
    }
    return check;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    string email;
    map<node,bool> friends;
};
class friendships{
    public:
        map<string,node>allEmails;
        void addemail(string email1){
            node a;
            a.email=email1;
            if(allEmails.find(email1)!=allEmails.end())
                cout<<email1<<"is already added"<<endl;
            allEmails[email1]=a;
        }
        void dfs()
        void befriend(string email1,string email2){
            if(allEmails.find(email1)==allEmails.end() || allEmails.find(email2)==allEmails.end()){
                cout<<"the email is not add";
                return;
            }
            node a=allEmails[email1];
            node b=allEmails[email2];
            a.friends.insert(email2);
            b.friends.insert(email1);




        }



};


int main(){

}