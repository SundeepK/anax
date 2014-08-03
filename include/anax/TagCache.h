#ifndef TAGCACHE_H_
#define TAGCACHE_H_

//#include <anax/Entity.hpp>
#include <unordered_map>
#include <BoostAnyHasher.h>
#include <boost/any.hpp>

namespace anax {

	class TagCache {

	public:

		TagCache(){}

		template<typename Tag_type>
		int getTagId(const Tag_type& tag) const;

		template<typename Tag_type>
		void putTag( Tag_type& tag, const int id);

		template<typename Tag_type>
		void eraseTag(const Tag_type& tag);

	private:

		std::unordered_map<boost::any, int, BoostAnyHasher> m_tagsToUniqueIds;
	};

		// return -1 if no id is found for tag
		template<typename Tag_type>
		int TagCache::getTagId(const Tag_type& tag) const {
			int tagId = -1;
			auto tagIterator = m_tagsToUniqueIds.find(tag);
			if (tagIterator != m_tagsToUniqueIds.end()) {
				tagId = tagIterator.second;
			}
			return tagId;
		}

		template<typename Tag_type>
		void TagCache::putTag( Tag_type& tag, const int id) {
			m_tagsToUniqueIds[boost::any(tag)] = id;
		}

		template<typename Tag_type>
		void TagCache::eraseTag(const Tag_type& tag){
			m_tagsToUniqueIds.erase(tag);
		}


}

#endif /* TAGCACHE_H_ */
