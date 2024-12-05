
#include <cstdio>
#include <iostream>
struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
  ConsoleLogger(const char *logPrefix) : logPrefix{logPrefix} {}

  void log_transfer(long from, long to, double amount) override {
    printf("[cons]: %s - %ld -> %ld: %f\n", logPrefix, from, to, amount);
  }

private:
  const char *logPrefix;
};

struct FileLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

struct AccountDatabase {
  virtual ~AccountDatabase() = default;
  virtual long retrieve(long bank_id, long amount) = 0;
  virtual void set(long bank_id, long amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
  long retrieve(long bank_id, long amount) override {
    std::cout << "Retrieving amount: " << amount
              << " from bank_id: " << bank_id;
    return amount;
  }

  void set(long bank_id, long amount) override {
    std::cout << "Setting amount: " << amount << " in bank_id: " << bank_id;
  }
};

// logger1 comes from constructor injection
// logger2 comes from property injection
struct Bank {
  Bank(Logger &logger, InMemoryAccountDatabase &db)
      : logger1{logger}, accountDb{db} {}

  void set_logger(Logger *new_logger) { logger2 = new_logger; }

  void make_transfer(long from, long to, double amount) {
    if (logger2) {
      logger2->log_transfer(from, to, amount);
    } else {
      logger1.log_transfer(from, to, amount);
    }
  }

private:
  Logger &logger1;
  Logger *logger2;
  AccountDatabase &accountDb;
};

int main() {
  ConsoleLogger logger{"prefix"};
  FileLogger fileLogger;
  InMemoryAccountDatabase db;
  Bank bank{logger, db};
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
  bank.set_logger(&fileLogger);
  bank.make_transfer(3000, 2000, 10.00);
}
