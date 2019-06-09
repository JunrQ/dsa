/*
 * 红黑树
 * 1. 树根始终为黑
 * 2. 外部节点为黑
 * 3. 其余节点若为红色，则其孩子节点必为黑色
 * 4. 从任一外部节点到根结点的沿途，黑色节点数目相等
 * 
 */


namespace dsa {


enum class Color {RED, BLACK};

template <typename T>
struct RBNode {
  
  Color color;
  RBNode* p;
  RBNode* left;
  RBNode* right;
  T key;

  RBNode(T& key, Color color=Color::BLACK) : p(nullptr), left(nullptr),
                   right(nullptr) {key = key; color=color;}
};




template <typename T>
class RBTree {

private:
  RBNode<T> root





};


} // namespace dsa


