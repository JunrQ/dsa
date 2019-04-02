


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


