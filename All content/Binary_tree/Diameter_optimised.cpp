#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *&root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void Level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
pair<int, int> fDiameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftside = fDiameter(root->left);
    pair<int, int> rightside = fDiameter(root->right);
    int a = leftside.first;
    int b = rightside.first;
    int h = leftside.second + rightside.second + 1;
    pair<int, int> ans;
    ans.first = max(a, max(b, h));
    ans.second = max(leftside.second, rightside.second) + 1;
    return ans;
}
int main()
{
    node *root;
    root = buildtree(root);
    Level_order_traversal(root);
    cout << fDiameter(root).first << endl;
}//1 2 3 -1 -1 4 -1 -1 5 -1 6 7 -1 -1 8 -1 -1