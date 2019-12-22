#include "application.hpp"

namespace prch {

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
{  }

Application::~Application() = default;

} // namespace prch
