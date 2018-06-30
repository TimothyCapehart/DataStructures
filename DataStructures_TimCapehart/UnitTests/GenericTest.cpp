#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "GenericTree.h"
#include <list>
#include <locale>
using std::list;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(GenericTreeTest)
	{
	public:

		TEST_METHOD(GenericTreeCopyConstructorTest)
		{
			CrtCheckMemory check;
			list<std::wstring> list_a;
			list<std::wstring> list_b;
			list_b.emplace_back(L"C:\\Test\\");
			list_b.emplace_back(L"C:\\Test\\textfile.txt");
			list_b.emplace_back(L"C:\\Test\\name");
			auto func = [&](const GenericTreeNode<std::wstring> * const p)
			{
				list_a.emplace_back(p->GetData());
			};
			GenericTreeNode<std::wstring> * root = new GenericTreeNode<std::wstring>(L"C:\\Test\\");
			GenericTreeNode<std::wstring> * child_a = new GenericTreeNode<std::wstring>(L"C:\\Test\\textfile.txt", root);
			root->AddChild(child_a);
			GenericTreeNode<std::wstring> * child_b = new GenericTreeNode<std::wstring>(L"C:\\Test\\name", root);
			root->AddChild(child_b);
			GenericTree<std::wstring> tree;
			tree.SetRoot(root);
			tree.SetFunction(func);
			GenericTree<std::wstring> copy(tree);
			copy.BreadthFirst();
			for (auto child : list_a)
			{
				auto expected = list_b.front();
				list_b.pop_front();
				Assert::AreEqual(expected, child);
			}
			tree.Purge();
			copy.Purge();
		}

		TEST_METHOD(GenericTreePurgeTest)
		{
			CrtCheckMemory check;
			list<std::wstring> list_a;
			auto func = [&](const GenericTreeNode<std::wstring> * const p)
			{
				list_a.emplace_back(p->GetData());
			};
			GenericTreeNode<std::wstring> * root = new GenericTreeNode<std::wstring>(L"C:\\Test\\");
			GenericTreeNode<std::wstring> * child_a = new GenericTreeNode<std::wstring>(L"C:\\Test\\textfile.txt", root);
			root->AddChild(child_a);
			GenericTreeNode<std::wstring> * child_b = new GenericTreeNode<std::wstring>(L"C:\\Test\\name", root);
			root->AddChild(child_b);
			GenericTree<std::wstring> tree;
			tree.SetRoot(root);
			tree.SetFunction(func);
			tree.Purge();
		}

	};
}