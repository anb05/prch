#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>

namespace prch {

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int& argc, char** argv);
    ~Application() override;

    explicit Application(const Application& ) = delete;
    explicit Application(Application&& )      = delete;

public:
    Application& operator= (const Application& ) = delete;
    Application& operator= (Application&& )      = delete;
};

} // namespace prch

#endif // APPLICATION_HPP
