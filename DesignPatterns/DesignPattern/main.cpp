#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& from) noexcept {
        from_ = from;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) noexcept {
        where_[key] = value;
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        columns_.insert(columns_.end(), columns.begin(), columns.end());
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        where_.insert(kv.begin(), kv.end());
        return *this;
    }

    std::string BuildQuery() const {
        std::ostringstream query;
        query << "SELECT ";

        if (columns_.empty()) {
            query << "* ";
        }
        else {
            for (size_t i = 0; i < columns_.size(); ++i) {
                query << columns_[i] << (i < columns_.size() - 1 ? ", " : " ");
            }
        }

        query << "FROM " << from_;

        if (!where_.empty()) {
            query << " WHERE ";
            size_t i = 0;
            for (const auto& [key, value] : where_) {
                query << key << "=" << value << (i < where_.size() - 1 ? " AND " : "");
                ++i;
            }
        }

        query << ";";

        return query.str();
    }

private:
    std::vector<std::string> columns_;
    std::string from_;
    std::map<std::string, std::string> where_;
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
    AdvancedSqlSelectQueryBuilder& AddCondition(const std::string& key, const std::string& operator_, const std::string& value) noexcept {
        conditions_[key] = std::make_pair(operator_, value);
        return *this;
    }

    std::string BuildQuery() const {
        std::ostringstream query;
        query << SqlSelectQueryBuilder::BuildQuery();

        if (!conditions_.empty()) {
            query.seekp(-1, std::ios_base::end);
            query << " AND ";
            size_t i = 0;
            for (const auto& [key, pair] : conditions_) {
                query << key << pair.first << pair.second << (i < conditions_.size() - 1 ? " AND " : "");
                ++i;
            }
            query << ";";
        }

        return query.str();
    }

private:
    std::map<std::string, std::pair<std::string, std::string>> conditions_;
};

int main() {
    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");
    query_builder.AddCondition("id", ">", "42");
    std::cout << query_builder.BuildQuery() << std::endl;
    return 0;
}
