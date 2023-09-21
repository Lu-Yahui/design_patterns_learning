#include <iostream>
#include <string>

class Button
{
public:
    virtual void Render() = 0;
};

class WindowsButton : public Button
{
public:
    void Render() override
    {
        std::cout << "WindowsButton is rendering" << std::endl;
    }
};

class HTMLButton : public Button
{
public:
    void Render() override
    {
        std::cout << "HTMLButton is rendering" << std::endl;
    }
};

class Dialog
{
public:
    void Render()
    {
        auto button = CreateButton();
        button->Render();
    }

    virtual Button *CreateButton() = 0;
};

class WindowsDialog : public Dialog
{
public:
    Button *CreateButton() override
    {
        return new WindowsButton();
    }
};

class WebDialog : public Dialog
{
public:
    Button *CreateButton() override
    {
        return new HTMLButton();
    }
};

int main(int argc, const char *argv[])
{
    {
        // windows dialog
        auto dialog = new WindowsDialog();
        dialog->Render();
    }

    {
        // web dialog
        auto dialog = new WebDialog();
        dialog->Render();
    }

    return 0;
}