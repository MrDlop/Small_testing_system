#include <bits/stdc++.h>

#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

void start(const std::string &console, const int tl,
           const std::string &name_task, bool flag = false) {
  std::promise<int> promise;
  std::future<int> future = promise.get_future();
  std::future<int> result =
      std::async(std::launch::async, system, console.c_str());
  std::future_status status = result.wait_for(std::chrono::milliseconds(tl));

  if (status == std::future_status::ready) {
    int r_gen = result.get();
    if (r_gen != 0) {
      if (flag) {
        std::cout << "WA";
      } else {
        std::cout << "RE " + name_task;
      }
      exit(0);
    }
  } else if (status == std::future_status::timeout) {
    std::cout << "TL " + name_task << std::endl;
    exit(0);
  } else {
    std::cout << "CHECKER ERROR" << std::endl;
    exit(0);
  }
}

int main() {
  int tl_gen = 1000;
  int tl_stress = 1000;
  int tl_main = 1000;
  int tl_checker = 1000;
  char type_checker = '0';
  bool is_py_gen = true;
  bool is_py_stress = true;
  bool is_py_main = true;
  bool is_py_checker = false;

  if (is_py_checker && type_checker == '0') {
    is_py_checker = false;
  }

  std::string path = R"(D:\Programming\checker)";
  std::string file_generator = path + R"(\generator.)" + (is_py_gen ? "py" : "cpp");
  std::string file_stress = path + R"(\stress.)" + (is_py_stress ? "py" : "cpp");
  std::string file_main = path + R"(\main.)" + (is_py_main ? "py" : "cpp");
  std::string file_checker = path + R"(\checker.)" + (is_py_checker ? "py" : "cpp");

  std::string path_to_exe = path;
  std::string run_file_generator = path_to_exe + R"(\testing_exe\generator.exe)";
  std::string run_file_stress = path_to_exe + R"(\testing_exe\stress.exe)";
  std::string run_file_main = path_to_exe + R"(\testing_exe\main.exe)";
  std::string run_file_checker = path_to_exe + R"(\testing_exe\checker.exe)";

  std::string path_to_out = path;
  std::string gen_out = path_to_out + R"(\testing_out\gen.txt)";
  std::string stress_out = path_to_out + R"(\testing_out\stress.txt)";
  std::string main_out = path_to_out + R"(\testing_out\main.txt)";

  std::string compile = R"(C:\mingw\bin\g++.exe)";
  std::string python_interpreter = R"(python)";

  // compiling cpp or set python run
  {
    if (!is_py_gen) {
      if (system((compile + " " + file_generator + " -o " + run_file_generator)
                     .c_str())) {
        std::cout << "CE GENERATOR";
        return 0;
      }
    } else {
      run_file_generator = python_interpreter + " " + file_generator;
    }
    if (!is_py_stress) {
      if (system((compile + " " + file_stress + " -o " + run_file_stress).c_str())) {
        std::cout << "CE STRESS";
        return 0;
      }
    } else {
      run_file_stress = python_interpreter + " " + file_stress;
    }
    if (!is_py_main) {
      if (system((compile + " " + file_main + " -o " + run_file_main).c_str())) {
        std::cout << "CE MAIN";
        return 0;
      }
    } else {
      run_file_main = python_interpreter + " " + file_main;
    }
    if (!is_py_checker) {
      if (system((compile + " " + file_checker + " -o " + run_file_checker).c_str())) {
        std::cout << "CE CHECKER";
        return 0;
      }
    } else {
      run_file_checker = python_interpreter + " " + file_checker;
    }
  }

  for (int num_of_test = 3;; num_of_test++) {
    std::cout << num_of_test << ' ' << std::flush;
    std::string gen_console = run_file_generator + " " +
                              std::to_string(num_of_test) + " >" + gen_out;
    std::string stress_console =
        run_file_stress + " <" + gen_out + " >" + stress_out;
    std::string main_console = run_file_main + " <" + gen_out + " >" + main_out;
    std::string checker_console = run_file_checker + " " + type_checker + " " + main_out + " " + stress_out;

    start(gen_console, tl_gen, "GENERATOR");
    start(stress_console, tl_stress, "STRESS");
    start(main_console, tl_main, "MAIN");
    start(checker_console, tl_checker, "CHECKER", true);

    std::cout << "OK\n";
  }
}