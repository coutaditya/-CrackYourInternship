float findMedian(struct Node *root)
{
      int n = 0;
      Node* cur = root;
      while(cur!=NULL){
          if(cur->left==NULL){
              n++;
              cur=cur->right;
          }
          else{
              Node* prev = cur->left;
              while(prev->right!=NULL && prev->right!=cur){
                  prev = prev->right;
              }
              if(prev->right==NULL){
                  prev->right = cur;
                  cur = cur->left;
              }
              else{
                  prev->right = NULL;
                  n++;
                  cur = cur->right;
              }
          }
      }
      
      int a = 0, b = 0;
      float x = 0, y = 0;
      
      if(n%2==1){
          a = n/2+1;
      }
      else{
          a = n/2;
          b = n/2+1;
      }
      n = 0;
      cur = root;
      while(cur!=NULL){
          if(cur->left==NULL){
              n++;
              if(n==a){
                  x = cur->data;
              }
              cur=cur->right;
          }
          else{
              Node* prev = cur->left;
              while(prev->right!=NULL && prev->right!=cur){
                  prev = prev->right;
              }
              if(prev->right==NULL){
                  prev->right = cur;
                  cur = cur->left;
              }
              else{
                  prev->right = NULL;
                  n++;
                  if(n==a){
                      x = cur->data;
                  }
                  if(n==b){
                      y = cur->data;
                  }
                  cur = cur->right;
              }
          }
      }
      
      if(y==0) return x;
      
      return (x+y)/2;
}