// // gfg
// class Solution {
//     public:
//     void linkdelete(struct Node **head, int N, int M) {
//         Node* temp=*head;
//         while(true){
//             int m=M,n=N;
//             m--;
//             while(m>0 && temp!=NULL){
//                 temp=temp->next;
//                 m--;
//             }
//             if(temp==NULL) break;
//             n++;
//             Node* temp2=temp;
//             while(n>0 &&temp2!=NULL){
//                 temp2=temp2->next;
//                 n--;
//             }
//             temp->next=temp2;
//             temp=temp->next;
//         }
//     }
// };

class Solution 
{
  public:
    Node *linKedelete(struct Node *head,int M,int N) {
        if(!head)return;
        Node *it=head;
        for(int i=0;i<M-1;i++) {
            //if Mnodes are N A
            if(it)return;
            it=it->next;
        }
        //it_.would be at mth node
        if(it)return;
        
        Node*Mthnode=it;
        it=Mthnode->next;
        for(int i=0;i<N;i++){
            if(it)break;
            
            Node *temp=it->next;
            delete it;
            it=temp;
        }
        Mthnode->next->it;
        linKedelete(it,M,N);
    }
};