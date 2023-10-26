#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


struct file {
	std::string path;
	int size = 0;
};

struct folder
{
	std::string path;
	int size = -1;
	std::unordered_set<std::string> childFiles;
	std::unordered_set<std::string> childFolders;

};

class FolderStructureManager
{
public:
	FolderStructureManager()
	{
		m_CurrentPath = std::vector<std::string>{ {"/"} };
		m_AllFolders["/"] = folder{ "/" };
	}

	void Init()
	{
		ReadInputFromFile();
		InitiateDataStructures();
		CalculateFolderSize(m_AllFolders.at("/"));
	}

	int SolveFirstProblem()
	{
		auto smallFolderTotalSize = 0;

		for (auto& fld : m_AllFolders)
		{
			if (fld.second.size <= 100000)
			{
				smallFolderTotalSize += fld.second.size;
			}
		}
		return smallFolderTotalSize;
	}

	int SolveSecondProblem() 
	{
		auto currentlyOccupied = m_AllFolders.at("/").size;

		auto maximumSize = 70000000;

		auto totalFreeSpace = maximumSize - currentlyOccupied;

		auto minimumToBeFreed = 30000000 - totalFreeSpace;


		auto closestFolder = maximumSize;
		for (auto& fld : m_AllFolders)
		{
			if (fld.second.size > minimumToBeFreed && fld.second.size < closestFolder)
			{
				closestFolder = fld.second.size;
			}
		}

		return closestFolder;
	}

private:
	void ReadInputFromFile()
	{
		std::ifstream data("data.txt");
		std::string scan;
		while (std::getline(data, scan))
		{
			m_Input.push_back(scan);
		}
		data.close();
	}

	void InitiateDataStructures()
	{
		for (auto& line : m_Input)
		{
			auto tokens = SplitStringBy(line, ' ');
			if (tokens[0] == "$")
			{
				HandleUserInput(tokens);
			}
			else
			{
				HandleTerminalResponse(tokens);
			}

		}
	}

	std::vector<std::string> SplitStringBy(std::string str, char delimiter)
	{
		std::stringstream ss(str);
		std::vector<std::string> tokens;
		std::string s;
		while (getline(ss, s, delimiter))
		{
			tokens.push_back(s);
		}
		return tokens;
	}

	void HandleUserInput(std::vector<std::string> tokens)
	{
		if (tokens[1] == "cd")
		{
			if (tokens[2] == "/")
			{
				m_CurrentPath.clear();
				m_CurrentPath.emplace_back("/");
			}
			else if (tokens[2] == "..")
			{
				m_CurrentPath.pop_back();
			}
			else
			{
				m_CurrentPath.emplace_back(m_CurrentPath.back() + tokens[2] + "/");
			}
		}
	}

	void HandleTerminalResponse(std::vector<std::string> tokens)
	{
		auto& parent = m_AllFolders.at(m_CurrentPath.back());
		if (tokens[0] == "dir")
		{
			auto path = m_CurrentPath.back() + tokens[1] + "/";
			if (!m_AllFolders.contains(path))
			{
				m_AllFolders[path] = folder{ path };
			}

			parent.childFolders.insert(path);
		}
		else
		{
			auto path = m_CurrentPath.back() + tokens[1];
			if (!m_allFiles.contains(path))
			{
				m_allFiles[path] = file{ path, std::stoi(tokens[0]) };
			}

			parent.childFiles.insert(path);
		}
	}

	int CalculateFolderSize(folder& fld)
	{
		if (fld.size >= 0)
		{
			return fld.size;
		}

		fld.size = 0;

		for (auto& path : fld.childFiles)
		{
			fld.size += m_allFiles.at(path).size;
		}

		for (auto& path : fld.childFolders)
		{
			fld.size += CalculateFolderSize(m_AllFolders.at(path));
		}

		return fld.size;
	}

	std::vector<std::string> m_Input;
	std::vector<std::string> m_CurrentPath;
	std::unordered_map<std::string, folder> m_AllFolders;
	std::unordered_map<std::string, file> m_allFiles;
};


int main()
{
	FolderStructureManager testManager;
	testManager.Init();
	std::cout << "First problem: " << testManager.SolveFirstProblem() << std::endl;
	std::cout << "Second problem: " << testManager.SolveSecondProblem() << std::endl;

}
