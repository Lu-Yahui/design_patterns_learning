#include <iostream>
#include <string>

// button interface
class Button
{
public:
    virtual void Click() = 0;
};

class WinButton : public Button
{
public:
    void Click() override
    {
        std::cout << "WinButton clicked" << std::endl;
    }
};

class MacButton : public Button
{
public:
    void Click() override
    {
        std::cout << "MacButton clicked" << std::endl;
    }
};

// check box interface
class CheckBox
{
public:
    virtual void Check() = 0;
};

class WinCheckBox : public CheckBox
{
public:
    void Check() override
    {
        std::cout << "WinCheckBox checked" << std::endl;
    }
};

class MacCheckBox : public CheckBox
{
public:
    void Check() override
    {
        std::cout << "MacCheckBox checked" << std::endl;
    }
};

// GUI factory interface
class GuiFactory
{
public:
    virtual Button *CreateButton() = 0;

    virtual CheckBox *CreateCheckBox() = 0;
};

class WinGuiFactory : public GuiFactory
{
public:
    Button *CreateButton() override
    {
        return new WinButton();
    }

    CheckBox *CreateCheckBox() override
    {
        return new WinCheckBox();
    }
};

class MacGuiFactory : public GuiFactory
{
public:
    Button *CreateButton() override
    {
        return new MacButton();
    }

    CheckBox *CreateCheckBox() override
    {
        return new MacCheckBox();
    }
};

GuiFactory *InitFactory(const std::string &os)
{
    if (os == "windows")
    {
        return new WinGuiFactory();
    }
    else if (os == "mac")
    {
        return new MacGuiFactory();
    }

    return nullptr;
}

int main(int argc, const char *argv[])
{
    // windows style GUI
    {
        std::cout << "--- Windows ---" << std::endl;
        auto factory = InitFactory("windows");
        auto button = factory->CreateButton();
        auto checkbox = factory->CreateCheckBox();
        button->Click();
        checkbox->Check();
    }

    // mac style GUI
    {
        std::cout << "--- Mac OS ---" << std::endl;
        auto factory = InitFactory("mac");
        auto button = factory->CreateButton();
        auto checkbox = factory->CreateCheckBox();
        button->Click();
        checkbox->Check();
    }

    return 0;
}