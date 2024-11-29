#include "3.h"


int genRand(std::string_view lim)
{
    int rnd = NULL;


    struct Lead
    {
        enum sign
        {
            or_,
            and_,
            unk_,
        };

        //int first_ind = NULL;
        //int second_ind = NULL;
        //int third_ind = NULL;
        //int fourth_ind = NULL;
        int first = NULL;
        int sec = NULL;
        sign sign_ = unk_;
        int priority = NULL;
        bool ext = false;
        //int fr_beg = NULL;
    };

    int max_priority = 0;
    std::deque <Lead> heap_lead;
    std::deque<std::string_view> heap;

    if (lim.find('(', 0) != std::string_view::npos) {

        int ind = NULL, cnt = NULL, firstind = -1, secondind = -1;
        std::string_view lim_1 = lim;
        int len = lim.length();
        int lst = NULL;

        Lead actual;

        while (ind < len)
        {
            if (lim_1[ind] == '(') {
                cnt++;
                if (firstind == -1)
                    firstind = ind;
            }
            else if (lim_1[ind] == ')' && cnt) {
                cnt--;
                if (!cnt && secondind == -1)
                    secondind = ind;
            }
            else if ((lim_1[ind] == '|' || lim_1[ind] == '&') && !cnt) {

                if (lim_1[ind] == '|')
                    actual.sign_ = Lead::or_;
                else
                    actual.sign_ = Lead::and_;

                actual.priority = max_priority;
                max_priority++; ind++;

                if (heap.back().find('(') != -1) {
                    actual.ext = true;
                    heap_lead.push_back(actual);
                    actual = Lead();
                }

                /*if (actual.first_ind == NULL && actual.second_ind == NULL)
                {
                    heap_lead.push_back(actual);
                    actual = Lead();
                }*/
            }

            ind++;

            if (firstind > -1 && secondind > -1) {

                /*if (actual.first_ind != NULL || actual.second_ind !=NULL)
                {
                    actual.third_ind = firstind;
                    actual.fourth_ind = secondind;
                }
                else
                {
                    actual.first_ind = firstind;
                    actual.second_ind = secondind;
                }*/

                heap.push_back(lim_1.substr(firstind + 1, secondind - firstind - 1));

                firstind = -1; secondind = -1;

                if (ind == len && !heap.empty()) {
                    if (!actual.ext && actual.sign_ != Lead::unk_)
                    {
                        actual.first = lst++;
                        actual.sec = lst++;
                        heap_lead.push_back(actual);
                        actual = Lead();
                    }
                    std::deque<std::string_view>::iterator _iter = heap.begin();
                    while (_iter != heap.end())
                    {
                        if ((*_iter).find('(') != std::string_view::npos)
                        {
                            ind = NULL;
                            lim_1 = *_iter;
                            len = lim_1.length();
                            heap.erase(_iter);
                            break;
                        }
                        _iter++;
                    }
                }
            }

        }
    }

    int ind = NULL;
    std::deque<int> vals;

    while (ind < heap_lead.size())
    {
        std::deque<Lead>::iterator iter_ = heap_lead.begin();
        while (iter_ != heap_lead.end())
        {
            if ((*iter_).priority == max_priority - 1 && (*iter_).sign_ != Lead::unk_)
                break;
            iter_++;
        }

        if (iter_ != heap_lead.end() && !(*iter_).ext) {

            std::string_view first = heap[(*iter_).first];//(lim.data() + (*iter_).first_ind + 1, (*iter_).second_ind - (*iter_).first_ind - 1);
            std::string_view second = heap[(*iter_).sec];//(lim.data() + (*iter_).third_ind + 1, (*iter_).fourth_ind - (*iter_).third_ind - 1);

            int max = std::numeric_limits<long>::max();
            int min = std::numeric_limits<long>::min();
            int pointer = NULL;
            bool exc = false;

            if (int indexx = first.find(">", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 1, first.data() + first.length(), min);
                assert(l_ == std::errc{});
                min += 1;
            }
            else if (int indexx = first.find(">=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 2, first.data() + first.length(), min);
                assert(l_ == std::errc{});
            }
            else if (int indexx = first.find("<", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 1, first.data() + first.length(), max);
                assert(l_ == std::errc{});
                max -= 1;
            }
            else if (int indexx = first.find("<=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 2, first.data() + first.length(), max);
                assert(l_ == std::errc{});
            }
            else if (int indexx = first.find("==", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 2, first.data() + first.length(), pointer);
                assert(l_ == std::errc{});
                exc = true;
            }
            else if (int indexx = first.find("!=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(first.data() + indexx + 2, first.data() + first.length(), pointer);
                assert(l_ == std::errc{});
            }

            if (int indexx = second.find(">", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 1, second.data() + second.length(), min);
                //min = std::atoi(second.data() + indexx + 1);
                assert(l_ == std::errc{});
                min += 1;
            }
            else if (int indexx = second.find(">=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 2, second.data() + second.length(), min);
                assert(l_ == std::errc{});
            }
            else if (int indexx = second.find("<", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 1, second.data() + second.length(), max);
                assert(l_ == std::errc{});
                max -= 1;
            }
            else if (int indexx = second.find("<=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 2, second.data() + second.length(), max);
                assert(l_ == std::errc{});
            }
            else if (int indexx = second.find("==", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 2, second.data() + second.length(), pointer);
                assert(l_ == std::errc{});
                exc = true;
            }
            else if (int indexx = second.find("!=", 0); indexx != std::string_view::npos)
            {
                auto [f_, l_] = std::from_chars(second.data() + indexx + 2, second.data() + second.length(), pointer);
                assert(l_ == std::errc{});
            }

            while (true) {
                if (max > min) {
                    if ((*iter_).sign_ == Lead::or_) {
                        std::random_device rnd;
                        std::mt19937 engine(rnd());

                        std::uniform_real_distribution<double> distr(min, std::numeric_limits<long>::max());
                        int end_val_1 = distr(engine);

                        distr = std::uniform_real_distribution<double>(std::numeric_limits<long>::min(), max);
                        int end_val_2 = distr(engine);

                        distr = std::uniform_real_distribution<double>(1, 2);
                        int res = distr(engine);

                        if (res == 1)
                            res = end_val_1;
                        else
                            res = end_val_2;

                        if (res == pointer && exc == true)
                            continue;
                        else {
                            vals.push_front(res);
                            break;
                        }
                    }
                    else if ((*iter_).sign_ == Lead::and_)
                    {
                        std::random_device rnd;
                        std::mt19937 engine(rnd());

                        std::uniform_real_distribution<double> distr(min, max);
                        int res = distr(engine);

                        if (res == pointer && exc == true)
                            continue;
                        else {
                            vals.push_front(res);
                            break;
                        }
                    }
                }
                else
                {
                    if ((*iter_).sign_ == Lead::or_) {
                        std::random_device rnd;
                        std::mt19937 engine(rnd());

                        std::uniform_real_distribution<double> distr(min, std::numeric_limits<long>::max());
                        int end_val_1 = distr(engine);

                        distr = std::uniform_real_distribution<double>(std::numeric_limits<long>::min(), max);
                        int end_val_2 = distr(engine);

                        distr = std::uniform_real_distribution<double>(1, 2);
                        int res = distr(engine);

                        if (res == 1)
                            res = end_val_1;
                        else
                            res = end_val_2;

                        if (res == pointer && exc == true)
                            continue;
                        else {
                            vals.push_front(res);
                            break;
                        }
                    }
                    else if ((*iter_).sign_ == Lead::and_)
                    {
                        throw std::runtime_error::runtime_error(""); //unvailable condition
                    }
                }
            }

        }
        else if (iter_ != heap_lead.end())
        {
            int first = vals.back(); vals.pop_back();
            int sec = vals.back(); vals.pop_back();

            std::random_device rnd;
            std::mt19937 engine(rnd());

            if ((*iter_).sign_ == Lead::and_ && first != sec) {

                throw std::runtime_error::runtime_error(""); //unvailable condition
            }
            else
            {
                std::uniform_real_distribution<double> distr(1, 2);
                int end_val = distr(engine);
                if (end_val == 1)
                    end_val = first;
                else
                    end_val = sec;
                vals.push_back(end_val);
            }
        }

        ind++;
        max_priority--;
    }


    return vals[0];
}