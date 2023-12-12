#include <memory>
#include <vector>

class Element;

class Element
{
};

class TriShell : public Element
{
public:
    TriShell() = default;

    std::unique_ptr<Element> clone()
    {
        return std::make_unique<TriShell>(*this);
    }
};

int main()
{
    std::vector<std::unique_ptr<TriShell>> elements1(100);

    for (int i = 0; i < 100; i++)
    {
        elements1[i] = std::make_unique<TriShell>();
    }

    std::vector<std::unique_ptr<Element>> elements2(elements1.size());

    for (int i = 0; i < elements1.size(); i++)
    {
        elements2[i].reset();
        elements2[i] = elements1[i]->clone();
    }
}
