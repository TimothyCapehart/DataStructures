//#include <iostream>
//#include <windows.h>
//#include <fileapi.h>
//#include <winuser.h>
//#include <handleapi.h>
//#include <fstream>
//#include "GenericTree.h"
//
//using std::ofstream;
//using std::ios;
//using std::endl;
//
//bool ListDirectoryContents(const wchar_t *sDir);
//bool ListDirectoryContents(GenericTreeNode<std::wstring> * sDir);
//
//int main()
//{
//	list<std::wstring> _list;
//	auto func = [&](const GenericTreeNode<std::wstring> * const p)
//	{
//		_list.emplace_back(p->GetData().c_str());
//	};
//	GenericTreeNode<std::wstring> *root = new GenericTreeNode<std::wstring>(L"C:\\Test\\");
//	GenericTree<std::wstring> tree;
//	tree.SetRoot(root);
//	tree.SetFunction(func);
//	ListDirectoryContents(root);
//	tree.BreadthFirst();
//	std::cin.get();
//	return 0;
//}
//
//bool ListDirectoryContents(const wchar_t *sDir)
//{
//	WIN32_FIND_DATA fdFile;
//	HANDLE hFind = NULL;
//	wchar_t sPath[2048];
//	ofstream file;
//	file.open("C:\\Users\\tcape\\source\\repos\\DataStructures\\DataStructures_TimCapehart\\DataStructures\\output.txt", ios::app);
//
//	/*DirectoryTree<wchar_t*> myDir;
//	DirectoryNode<wchar_t*> oldRoot, newRoot;
//	oldRoot = myDir.GetRoot();*/
//
//	//Specify a file mask. *.* = We want everything! 
//	wsprintf(sPath, L"%s\\*.*", sDir);
//
//	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
//	{
//		wprintf(L"Path not found: [%s]\n", sDir);
//		file << "Path not found: " << sDir << "\n";
//		return false;
//	}
//
//	do
//	{
//		//Find first file will always return "."
//		//    and ".." as the first two directories. 
//		if (wcscmp(fdFile.cFileName, L".") != 0
//			&& wcscmp(fdFile.cFileName, L"..") != 0)
//		{
//			//Build up our file path using the passed in 
//			//  [sDir] and the file/foldername we just found: 
//			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
//			file << sPath << sDir << "\\" << fdFile.cFileName;
//
//			//myDir.InsertDirectory(oldRoot, sPath);
//			//Is the entity a File or Folder? 
//			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
//			{
//				wprintf(L"Directory: %s\n", sPath);
//				file << sPath << "Directory: " << sPath << endl;
//				ListDirectoryContents(sPath);
//			}
//			else {
//				wprintf(L"File: %s\n", sPath);
//				file << "File: " << sPath << endl;
//			}
//		}
//	} while (FindNextFile(hFind, &fdFile)); //Find the next file. 
//
//	FindClose(hFind); //Always, Always, clean things up! 
//
//	return true;
//}
//
//bool ListDirectoryContents(GenericTreeNode<std::wstring> *sDir)
//{
//	WIN32_FIND_DATA fdFile;
//	HANDLE hFind = NULL;
//	wchar_t sPath[2048];
//	ofstream file;
//	file.open("C:\\Users\\tcape\\source\\repos\\DataStructures\\DataStructures_TimCapehart\\DataStructures\\output.txt", ios::app);
//
//
//	/*DirectoryTree<wchar_t*> myDir;
//	DirectoryNode<wchar_t*> oldRoot, newRoot;
//	oldRoot = myDir.GetRoot();*/
//
//	//Specify a file mask. *.* = We want everything! 
//	wsprintf(sPath, L"%s\\*.*", sDir->GetData().c_str());
//
//	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
//	{
//		wprintf(L"Path not found: [%s]\n", sDir);
//		file << "Path not found: " << sDir << "\n";
//		return false;
//	}
//
//	do
//	{
//		//Find first file will always return "."
//		//    and ".." as the first two directories. 
//		if (wcscmp(fdFile.cFileName, L".") != 0
//			&& wcscmp(fdFile.cFileName, L"..") != 0)
//		{
//			//Build up our file path using the passed in 
//			//  [sDir] and the file/foldername we just found: 
//			wsprintf(sPath, L"%s\\%s", sDir->GetData().c_str(), fdFile.cFileName);
//			file << sPath << sDir << "\\" << fdFile.cFileName;
//
//			//myDir.InsertDirectory(oldRoot, sPath);
//			//Is the entity a File or Folder? 
//			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
//			{
//				wprintf(L"Directory: %s\n", sPath);
//				file << sPath << "Directory: " << sPath << endl;
//				GenericTreeNode<std::wstring> * newDir = new GenericTreeNode<std::wstring>(sPath, sDir);
//				sDir->AddChild(newDir);
//				ListDirectoryContents(newDir);
//			}
//			else 
//			{
//				wprintf(L"File: %s\n", sPath);
//				file << "File: " << sPath << endl;
//				GenericTreeNode<std::wstring> * newFile = new GenericTreeNode<std::wstring>(sPath, sDir);
//				sDir->AddChild(newFile);
//			}
//		}
//	} while (FindNextFile(hFind, &fdFile)); //Find the next file. 
//
//	FindClose(hFind); //Always, Always, clean things up! 
//
//	return true;
//}