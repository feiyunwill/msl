/**
 * Copyright (c) 2016-2017 Netflix, Inc.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_ENTITYAUTH_UNAUTHENTICATEDAUTHENTICATIONFACTORY_H_
#define SRC_ENTITYAUTH_UNAUTHENTICATEDAUTHENTICATIONFACTORY_H_

#include <entityauth/EntityAuthenticationFactory.h>

namespace netflix {
namespace msl {
namespace util { class AuthenticationUtils; }
namespace entityauth {

/**
 * <p>Unauthenticated entity authentication factory.</p>
 *
 * @author Wesley Miaw <wmiaw@netflix.com>
 */
class UnauthenticatedAuthenticationFactory : public EntityAuthenticationFactory
{
public:
    virtual ~UnauthenticatedAuthenticationFactory() {}

    /**
     * Construct a new unauthenticated authentication factory instance.
     *
     * @param authutils authentication utilities.
     */
    UnauthenticatedAuthenticationFactory(std::shared_ptr<util::AuthenticationUtils> authutils);

    /* (non-Javadoc)
     * @see com.netflix.msl.entityauth.EntityAuthenticationFactory#createData(com.netflix.msl.util.MslContext, com.netflix.msl.io.MslObject)
     */
    virtual std::shared_ptr<EntityAuthenticationData> createData(
            std::shared_ptr<util::MslContext> ctx,
            std::shared_ptr<io::MslObject> entityAuthMo);

    /* (non-Javadoc)
     * @see com.netflix.msl.entityauth.EntityAuthenticationFactory#getCryptoContext(com.netflix.msl.util.MslContext, com.netflix.msl.entityauth.EntityAuthenticationData)
     */
    virtual std::shared_ptr<crypto::ICryptoContext> getCryptoContext(
            const std::shared_ptr<util::MslContext> ctx,
            std::shared_ptr<EntityAuthenticationData> authdata);

private:
    UnauthenticatedAuthenticationFactory(); // not implemented

private:
    /** Authentication utilities. */
    const std::shared_ptr<util::AuthenticationUtils> authutils_;
};

}}} // namespace netflix::msl::entityauth

#endif /* SRC_ENTITYAUTH_UNAUTHENTICATEDAUTHENTICATIONFACTORY_H_ */
