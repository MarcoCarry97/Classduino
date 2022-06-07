#ifndef OnClick

namespace interfaces
{
    virtual class OnClick
    {
        protected:
            []() onClick;

        public:
            void setOnClickListener([]() onClick);
    }
}

#endif