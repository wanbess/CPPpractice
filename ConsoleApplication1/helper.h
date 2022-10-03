#include<vector>

template<class Ty,class... Args>
using Resulsof = decltype(Ty(Args)...);