using namespace std;
struct Content{
      
      void Set_Content(string a1, string b[]);
      void Set_Content(string a1, string a2);
      string user_answer;
      string Sentence,choice[4],attach_info;
      bool if_choice;
      void Print(int i);
}; 
struct Question{
     // Question();
      void Set_Question(string b);
      void give_answer(string in);
      
      bool state;
      Content special;
      string answer;
};
struct User{
      string name;
      Content* q[10];
      User(string n);
      void correct(int i);
      void see_state();
};  
