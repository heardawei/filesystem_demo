#include "ghc/filesystem.hpp"

namespace fs = ghc::filesystem;

int main()
{
  // 结论：使用fs::directory_iterator，fs::recursive_directory_iterator时
  // 内部使用shared_ptr共享数据。
  // 普通拷贝=shared_ptr增加引用计数=浅拷贝。
  // 需使用path作为参数构造一份全新的iter

  fs::recursive_directory_iterator iter1;

  // 浅拷贝，iter1与iter2内部指向同一份数据
  fs::recursive_directory_iterator iter2 = iter1;

  // 生成全新的iter，iter1与iter3内部无任何联系
  fs::recursive_directory_iterator iter3(iter1->path());

  return 0;
}
